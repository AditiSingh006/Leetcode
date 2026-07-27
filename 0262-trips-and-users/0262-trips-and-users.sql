# Write your MySQL query statement below
SELECT
    T.request_at AS 'Day',
    ROUND(
        1-( SUM(T.status='completed')/COUNT(T.id) )
    ,2) AS 'Cancellation Rate'
FROM Trips T JOIN Users C 
    ON T.client_id=C.users_id
JOIN Users D 
    ON T.driver_id=D.users_id
WHERE D.banned='No' AND C.banned='No'
GROUP BY T.request_at
HAVING T.request_at BETWEEN "2013-10-01" AND "2013-10-03"