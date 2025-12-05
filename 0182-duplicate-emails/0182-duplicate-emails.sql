# Write your MySQL query statement below
SELECT EMAIL from Person
group by email
having count(email)>1;