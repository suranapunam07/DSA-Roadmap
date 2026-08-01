# Write your MySQL query statement below
SELECT
   p.FirstName,
   p.LastName,
   a.city,
   a.state
FROM Person p
LEFT JOIN Address a
ON p.PersonId = a.PersonId
