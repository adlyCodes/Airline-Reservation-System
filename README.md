# 🎟️ Airline Reservation System (C Language)

This is a simple **Airline Reservation System** written in **C**, designed to simulate managing seats, storing data, and handling ticket reservations using file operations.

---

## 📁 Project Structure

| File         | Description                                      |
|--------------|--------------------------------------------------|
| `main.c`     | Main source code containing the program logic    |
| `data.txt`   | Stores registered customer or ticket data        |
| `seats.txt`  | Tracks seat availability                         |
| `tickets.txt`| Records issued ticket information                |

> 🧹 All build files and IDE-specific configs have been intentionally ignored.

---

## ⚙️ Features

- View available seats
- Reserve seats
- Issue and store tickets
- Save all data persistently using file handling

---

## 🧑‍💻 How to Compile and Run

### 💻 Linux / macOS

```bash
gcc -o ticket_system main.c
./ticket_system
```

### 🪟 Windows (Using Command Prompt)

Assuming you have GCC (MinGW) installed and added to `PATH`:

```cmd
gcc -o ticket_system.exe main.c
ticket_system.exe
```

### 🧰 Using an IDE (Optional)

You may also open the `main.c` file in your preferred IDE (like Code::Blocks or CLion) and run it directly.

---

## 📌 Requirements

- C compiler (GCC, clang, or equivalent)
- Basic terminal/console interface
- No external libraries needed

---

## 📝 Notes

- All seat and ticket data is stored in text files so it **persists** between runs.
- You can reset the system by manually clearing the contents of `seats.txt`, `tickets.txt`, and `data.txt`.

---

## 🙋 Author

**Ahmed Hossam Eldin Adly Abdelfattah**

---

## 📄 License

This project is open-source and free to use for learning and personal projects.
