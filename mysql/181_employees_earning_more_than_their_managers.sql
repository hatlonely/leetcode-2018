SELECT Name AS Employee
FROM Employee AS t1
WHERE ManagerId IS NOT NULL
AND Salary>(
    SELECT Salary
    FROM Employee
    WHERE Id=t1.ManagerId
);