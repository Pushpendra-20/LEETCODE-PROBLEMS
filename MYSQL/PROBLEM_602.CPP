/*
====================================================
LeetCode Problem: Friend Requests II - Who Has the Most Friends
Problem Number: 602

Approach:
- Create a derived table that
  combines:
    - requester_id
    - accepter_id

- Use UNION ALL so that every
  accepted friendship contributes
  one count to both users.

- Group the combined records by
  user id.

- Count the total number of
  friendships for each user using
  COUNT(*).

- Sort the results in descending
  order of friend count.

- Return the first row using
  LIMIT 1.

Query:

SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
) AS friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;

Why this approach?
- Every accepted request represents
  one friendship for both the
  requester and the accepter.
- UNION ALL preserves every record
  without removing duplicates.
- GROUP BY calculates the total
  number of friends for each user.
- ORDER BY and LIMIT identify the
  user with the highest friend
  count.

Example:

RequestAccepted

+--------------+-------------+
| requester_id | accepter_id |
+--------------+-------------+
| 1            | 2           |
| 1            | 3           |
| 2            | 3           |
+--------------+-------------+

Combined IDs:
1, 1, 2, 2, 3, 3

Friend Counts:
1 → 2
2 → 2
3 → 2

Output:
Any one of the users with
friend count = 2.

Time Complexity: O(n log n)

Space Complexity: O(n)

Where:
n = number of accepted friend
requests

Key Concepts:
- SQL
- UNION ALL
- GROUP BY
- COUNT
- ORDER BY
- Aggregate Functions

====================================================
*/




SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
) AS friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;
