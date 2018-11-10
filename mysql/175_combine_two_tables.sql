SELECT FirstName, LastName, City, State
FROM Address RIGHT JOIN Person ON Address.PersonId=Person.PersonId;