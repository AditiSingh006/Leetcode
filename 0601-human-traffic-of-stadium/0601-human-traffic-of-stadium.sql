# Write your MySQL query statement below
WITH ConsecutiveRows AS( SELECT id, visit_date, people, id - ROW_NUMBER() OVER (ORDER BY id) AS grp FROM Stadium
WHERE people >= 100),
GroupedRecords AS ( SELECT grp, COUNT(*) AS count_rows, MIN(id) AS start_id, MAX(id) AS end_id
FROM ConsecutiveRows GROUP BY grp HAVING COUNT(*) >= 3)
SELECT s.id, s.visit_date, s.people
FROM Stadium s JOIN GroupedRecords g ON
s.id BETWEEN g.start_id AND g.end_id
ORDER BY s.visit_date ASC;