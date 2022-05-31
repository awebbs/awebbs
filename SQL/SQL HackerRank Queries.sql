/*SQL HackerRank Queries Used in Solved Challenges

Prompt:
Query all columns for all American cities in the CITY table with populations
larger than 100000. The COUNTRYCODE for America is USA.*/

select *
from city
where countrycode = 'USA'
and population > 100000;

/*Prompt:
Query the name field for all American cities in the CITY table with 
populations larger than 120000. The COUNTRYCODE for America is USA.*/

select name
from city
where population > 120000
and countrycode = 'USA';

/*Prompt:
Query a list of CITY names from STATION for cities that have an even
ID number. Print the results in any order, but exclude duplicates from
the answer.*/

select distinct city
from station
where mod(id,2) = 0;

/*Prompt:
Find the difference between the total number of CITY entries in the table
and the number of distinct CITY entries in the table.*/

select count(city) - count(distinct city)
from station;

/*Prompt:
Query the two cities in STATION with the shortest and longest CITY names,
as well as their respective lengths. If there is more than one smallest
or largest city, choose the one that comes first when ordered alphabetically.*/

select city, length(city) from station ordered by length(city) desc, city asc limit 1;

select city, length(city) from station ordered by length(city) asc, city asc limit 1;

/*Prompt: 
Write a query that prints a list of employee names from the 
EMPLOYEE table in alaphabetical order.*/

select name
from employee
order by name asc;

/*Prompt:
Write a query that prints a list of employee names for employees in EMPLOYEE
having a salary greater than $2000 per month who have been employees for
less than 10 months. Sort your result by ascending employee_id.*/

select name
from employee
where salary > 2000 and months < 10;
