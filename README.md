# TrackNBook

<hr><br>

**DS Project**

This project is a Ticket Booking System implemented in C, designed to manage and book transportation tickets using various data structures. The system operates through a Command Line Interface (CLI) and utilizes several key data structures for efficient data management and processing.

## Features

- **User Registration and Authentication**
  - Users can register with a new username and password.
  - Existing users can log in using their credentials.
  - Admins have special access with predefined credentials for administrative tasks.

- **Administrative Functions**
  - Admins can add new stations to the Orange Line or Aqua Line.
  - Admins can view the list of registered users.
  - Admins can send and manage notifications.

- **User Functions**
  - Users can book cabs, buses, and metro tickets.
  - Users can view their previous bookings.
  - Users can hide their ID from the booking history.

## Data Structures Used

1. **Linked List**
   - Used for managing the list of stations in both the Orange Line and Aqua Line.

2. **Double Linked List**
   - Utilized for managing notifications, allowing for both forward and backward traversal.

3. **Stack**
   - Implemented for maintaining history of user actions and interactions.

4. **Queue**
   - Used for booking management, including adding and removing bookings in FIFO order.

5. **Graph**
   - Represents the locations and routes in Nagpur, supporting shortest path calculations.

## Functionality

- **User Registration**
  - Checks if the username already exists.
  - Validates that the entered passwords match before creating a new account.

- **User Login**
  - Validates user credentials against stored usernames and passwords.
  - Allows access to different functionalities based on user roles (admin or regular user).

- **Admin Features**
  - Add stations to existing lines.
  - View all registered users.
  - Send and delete notifications.

- **User Features**
  - Book tickets for cabs, buses, or metro with price calculations.
  - View previous bookings.
  - Hide user ID from history.

## System Requirements

- **Language**: C

