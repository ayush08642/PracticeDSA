SELECT 
cc.customer_name, 
pp.product_name,
COALESCE(sum(inv_item.quantity), 0) AS quantity
FROM invoice i 
JOIN customer cc 
ON cc.id = i.customer_id 
JOIN invoice_item inv_item
ON inv_item.invoice_id = i.id 
JOIN product pp 
ON inv_item.product_id = pp.id
GROUP BY cc.customer_name, pp.product_name 
UNION ALL
SELECT cc.customer_name, "N/A", 0 
FROM customer cc
WHERE NOT EXISTS 
(
    SELECT 1 FROM invoice i 
    WHERE i.customer_id = cc.id
)
UNION ALL 
SELECT "N/A", pp.product_name, 0 
FROM product pp
WHERE NOT EXISTS 
(
    SELECT 1 
    FROM invoice_item inv_item 
    WHERE inv_item.product_id = pp.id
);


