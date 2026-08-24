# Write your MySQL query statement below
SELECT 
    p.product_id,
    COALESCE(p.new_price, 10) AS price
FROM Products p
LEFT JOIN Products p2
    ON p.product_id = p2.product_id
    AND p2.change_date <= '2019-08-16'
WHERE p.change_date <= '2019-08-16'
  AND p.change_date = (
      SELECT MAX(change_date)
      FROM Products
      WHERE product_id = p.product_id
        AND change_date <= '2019-08-16'
  )

UNION

SELECT DISTINCT
    product_id,
    10 AS price
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
);