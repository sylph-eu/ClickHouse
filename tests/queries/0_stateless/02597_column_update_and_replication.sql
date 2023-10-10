CREATE TABLE test (
    `c_id` String,
    `p_id` String,
    `d` String
)
ENGINE = ReplicatedMergeTree('/clickhouse/tables/{database}/test/test_table', '1')
ORDER BY (c_id, p_id);


---CREATE TABLE test_r2 (
---    `c_id` String,
---    `p_id` String,
---    `d` String
---)
---ENGINE = ReplicatedMergeTree('/clickhouse/tables/{database}/test/test_table', '2')
---ORDER BY (c_id, p_id);


INSERT INTO test SELECT '1', '11', '111' FROM numbers(3);

INSERT INTO test SELECT '2', '22', '22' FROM numbers(3);

select * from test format Null;
select min(c_id) from test group by d format Null;

set mutations_sync=0;

ALTER TABLE test UPDATE d = d || toString(sleepEachRow(0.1)) where 1;

ALTER TABLE test ADD COLUMN x UInt32 default 0;
ALTER TABLE test UPDATE x = x + 1 where 1;
ALTER TABLE test DROP COLUMN x SETTINGS mutations_sync = 2;

SELECT * FROM system.mutations WHERE database=currentDatabase() AND table='test' AND NOT is_done;



select * from test format Null;


DROP TABLE test;
--DROP TABLE test_r2;
