# Write your MySQL query statement below
SELECT results FROM (
    SELECT u.name AS results
    FROM MovieRating mr
    JOIN Users u ON u.user_id = mr.user_id
    GROUP BY mr.user_id
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
) AS top_user

UNION ALL

SELECT results FROM (
    SELECT m.title AS results
    FROM MovieRating mr
    JOIN Movies m ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01' AND mr.created_at <= '2020-02-29'
    GROUP BY mr.movie_id
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
) AS top_movie;