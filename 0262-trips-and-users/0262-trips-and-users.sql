
with valid_rows as (
    select id, status, request_at
    from Trips t
    join Users u
    on t.client_id = u.users_id 
    join Users u1
    on t.driver_id = u1.users_id
    where u.banned = 'No' and u1.banned = 'No'
    and request_at between "2013-10-01" and "2013-10-03"
)

select request_at as 'Day', round(sum(status != 'completed') / count(status), 2) as 'Cancellation Rate'
from valid_rows 
group by request_at
