# 💰 Banking System in C++

This is a simple object-oriented **Banking System** built in C++. It allows basic banking operations such as deposits, withdrawals, fund transfers, and transaction history viewing for customers.

---

## 🧩 Features

- 👤 **Customer Management**: Each customer has a unique ID and account.
- 💸 **Deposits & Withdrawals**: Update account balance with proper checks.
- 🔁 **Fund Transfers**: Transfer money between customer accounts with logs.
- 📄 **Transaction History**: Logs every activity with timestamps.
- 💼 **Balance Inquiry**: View current account balance and recent transactions.

---

## 📂 File Structure

banking_system.cpp // Main source code
README.md // Project documentation

yaml
Copy
Edit

---

## 🛠 Technologies Used

- Language: C++
- Concepts: OOP (Classes & Objects), File-less data handling (in-memory), Timestamps

---

## 🚀 How to Run

1. Open terminal / your favorite C++ IDE.
2. Compile the source code:
   ```bash
   g++ banking_system.cpp -o banking_system
Run the program:

bash
Copy
Edit
./banking_system
📦 Sample Menu Options
markdown
Copy
Edit
1. Deposit
2. Withdraw
3. Transfer
4. View Balance
5. View Transactions
6. Exit
🧪 Sample Flow
Customer A (Alice) deposits ₹1000

Withdraws ₹200

Transfers ₹300 to Customer B (Bob)

Views balance and transaction history

📌 Notes
Transactions are stored in memory for the current session only.

You can easily extend this project with:

File-based account persistence

Admin panel for viewing all customers

Password-protected login system

📬 Feedback
Open to improvements and contributions for advanced features like multi-user support, file-based databases, or GUI.
