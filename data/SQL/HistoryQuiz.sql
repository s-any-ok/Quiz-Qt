Create table dbo.Questions
(
Id UNIQUEIDENTIFIER PRIMARY KEY DEFAULT (NEWID()),
Question varchar (1000) NOT NULL
)

insert into dbo.Questions values (
default,
'як звали людей €к≥ першими латали на л≥таку?'
)

select * from dbo.Questions

DROP TABLE dbo.Questions;

Create table dbo.Answers
(
Id UNIQUEIDENTIFIER PRIMARY KEY DEFAULT (NEWID()),
QuestionId UNIQUEIDENTIFIER NOT NULL,
Answer varchar (1000) NOT NULL,
isCorrect BIT
)

insert into dbo.Answers values (
default,
'B7E92E8B-12A4-4776-A291-0313576EF9AE',
'≤ван  ожедуб',
0
)

select * from dbo.Answers

DROP TABLE dbo.Answers;