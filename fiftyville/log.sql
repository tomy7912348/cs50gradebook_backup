-- Keep a log of any SQL queries you execute as you solve the m
SELECT id, year, month, day, street, description FROM crime_scene_reports;
SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

SELECT person_id, people.passport_number, people.name, people.phone_number, phone_calls.receiver, phone_calls.duration, bakery_security_logs.license_plate, atm_transactions.account_number, amount FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw" AND activity = "exit" AND minute > 14 AND minute < 26 AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 ;

SELECT activity, license_plate, minute FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

SELECT receiver FROM phone_calls WHERE receiver IN (SELECT phone_calls.receiver FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw" AND activity = "exit" AND minute > 14 AND minute < 26 AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28);

SELECT name, phone_number FROM people WHERE phone_number IN (SELECT phone_calls.receiver FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw" AND activity = "exit" AND minute > 14 AND minute < 26 AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28);

SELECT flights.id, full_name, city, destination_airport_id FROM flights, airports
WHERE year = 2021 AND month = 7 AND day = 29 AND destination_airport_id = airports.id;

SELECT flights.id, destination_airport_id, hour, minute FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = 8 ORDER BY hour;

SELECT passport_number, seat FROM passengers WHERE flight_id = 36;

SELECT passport_number FROM people WHERE