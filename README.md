# passgen — secure password generator for system administrators

**passgen** is a hardened command-line utility for generating secure passwords  
in infrastructure, sysadmin, and automation environments. It focuses on practicality, speed, and system-level reliability.

---

## ⚙️ Key Features

- Offline password generator (no telemetry, no internet access)
- Fully self-contained Linux x86_64 static binary
- Customizable output (letters, digits, symbols)
- Generates one or multiple passwords at once
- Output to terminal or file
- Secure file deletion supported

---

## 📥 Download

Get the latest release from [Releases](https://github.com/SilentPuck/passgen/releases):

```bash
wget https://github.com/SilentPuck/passgen/releases/download/v1.1/passgen
chmod +x passgen
```

---

## 🔧 Quick Example

```bash
./passgen -n 20 -l -d -s -c 3 
```

This command generates 3 passwords, 20 characters each, using letters, digits, and symbols.

---

## 🧪 Basic CLI

```text
  -n <number>      Password length (min: 8)
  -c <number>      Number of passwords to generate (default: 1)
  -l               Use letters (a-z, A-Z)
  -d               Use digits (0-9)
  -s               Use special characters (!@#$...)
  -o <filename>    Save passwords to file
  --auto-name      Auto-generate file name
  --remove         Securely delete file
  --silent         Do not print to terminal
  --version        Show version info
  --help           Show help
```

---

## ✅ Reliability

- CI validates binary execution on every commit
- Built and tested with:
  - `-fsanitize=address`
  - `-fsanitize=undefined`
  - `valgrind --leak-check=full`

This is a binary-only release.  
No source code is distributed publicly.

---

## 📚 Documentation

See the [Wiki](https://github.com/SilentPuck/passgen/wiki) for full details, including:

- Real-world sysadmin usage
- Password scripting examples
- File handling and secure deletion
- Project goals and philosophy

---

## 💸 Donate

Support development via [Wiki → Donate](https://github.com/SilentPuck/passgen/wiki/Donate)

---

🛠️ Built with clarity and intent by [SilentPuck](https://github.com/SilentPuck)