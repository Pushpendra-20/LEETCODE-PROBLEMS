/*
====================================================
LeetCode Problem: Find Books with No Available Copies
Problem Number: 3642

Approach:

- Join the Library_Books table
  with Borrowing_Records using
  book_id.

- Filter only the books that are
  currently borrowed by selecting
  records where:
      return_date IS NULL

- Group the records by each book.

- Count the number of active
  borrowers for every book using:
      COUNT(br.book_id)

- Compare this count with the
  total number of copies available
  for that book.

- If:
      current borrowers
      ==
      total copies

  then every copy is currently
  borrowed, meaning no copies are
  available.

- Return the required book
  information along with the
  number of current borrowers.

- Sort the result by:
    1. current_borrowers (DESC)
    2. title (ASC)

Query:

SELECT
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    COUNT(br.book_id) AS current_borrowers
FROM library_books lb
JOIN borrowing_records br
ON lb.book_id = br.book_id
WHERE br.return_date IS NULL
GROUP BY
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    lb.total_copies
HAVING COUNT(br.book_id) = lb.total_copies
ORDER BY current_borrowers DESC,
         title ASC;

----------------------------------------------------
Why this approach?

- INNER JOIN connects books with
  their borrowing records.

- WHERE filters only books that
  are currently borrowed.

- GROUP BY collects all active
  borrowings for each book.

- HAVING compares the active
  borrow count with the total
  number of copies.

- Only books whose every copy is
  currently borrowed are returned.

----------------------------------------------------
Example

Library_Books

+---------+-----------+--------------+
| book_id | title     | total_copies |
+---------+-----------+--------------+
| 1       | SQL Guide | 2            |
| 2       | C++ Book  | 3            |
+---------+-----------+--------------+

Borrowing_Records

+---------+-------------+
| book_id | return_date |
+---------+-------------+
| 1       | NULL        |
| 1       | NULL        |
| 2       | NULL        |
| 2       | NULL        |
+---------+-------------+

Output

+---------+-----------+-------------------+
| book_id | title     | current_borrowers |
+---------+-----------+-------------------+
| 1       | SQL Guide | 2                 |
+---------+-----------+-------------------+

----------------------------------------------------
Time Complexity

O(n)

where n is the number of
borrowing records.

----------------------------------------------------
Space Complexity

O(k)

where k is the number of
distinct books after grouping.

----------------------------------------------------
Key Concepts

- SQL
- INNER JOIN
- GROUP BY
- HAVING
- COUNT
- ORDER BY
- Aggregate Functions

----------------------------------------------------
Note

Using HAVING after GROUP BY
allows comparison between the
number of active borrowings and
the total copies of each book.
This efficiently identifies books
that currently have no available
copies.

====================================================
*/


SELECT 
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    COUNT(br.book_id) AS current_borrowers
FROM library_books lb
JOIN borrowing_records br
ON lb.book_id = br.book_id
WHERE br.return_date IS NULL
GROUP BY
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    lb.total_copies
HAVING COUNT(br.book_id) = lb.total_copies
ORDER BY current_borrowers DESC, title ASC;
