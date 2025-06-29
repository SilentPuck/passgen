# 🔐 passgen — password generator for paranoids

Simple. Fast. Offline. No tracking. No telemetry. Just security.

## 🛠 Features

- Password generation with custom charset:
  - Letters `a-zA-Z`
  - Digits `0-9`
  - Special characters `!@#$%^&*`
- Multiple password generation (`-c`)
- Save to file with `-o` or `--auto-name`
- Secure delete with `--remove`
- Silent mode for scripts
- Fully offline and private
- Lightweight static binary (Linux x86_64)
- No dependencies, no telemetry

## 📥 Download

You can download the latest release from the [Releases](https://github.com/SilentPuck/passgen/releases) section.

```bash
wget https://github.com/SilentPuck/passgen/releases/download/v1.1/passgen
chmod +x passgen
```

> ✅ Recommended: verify signature and checksum.

## 🧪 Usage

```bash
./passgen -n 16 -l -d -s -c 5 -o mylist.txt
```

### CLI Options

```text
  -n <number>      Password length (min: 8)
  -c <number>      Number of passwords (default: 1)
  -l               Use letters (a-z, A-Z)
  -d               Use digits (0-9)
  -s               Use special characters (!@#$...)
  -o <filename>    Save to specific file
  --auto-name      Auto-generate filename (passgen_YYYYMMDD_HHMMSS.txt)
  --remove         Securely delete specified file
  --silent         Suppress terminal output
  --version        Show version info
  --help           Show this help message
```
## 🔒 Security

- Written in C
- Compiled with full memory safety: ASan, UBSan, Valgrind
- Hardened with strict compiler flags

## 🧪 Testing

CI runs every commit via GitHub Actions:

- Builds from `src/` via `Makefile`
- Runs sanitizers (`-fsanitize`)
- Runs `valgrind`
- Executes `test/test_passgen.c`

To run locally:

```bash
make           # build
valgrind ./bin/passgen --length 12
gcc -o test/test test/test_passgen.c && ./test/test

---


## 💸 Donate

If you find this tool useful and want to support its development:

### 🟠 Monero (XMR)
```
46vt374N1tRduTQZFodskNbqygTnkFFo3SLJ8btmGkbyFpib65qFVMycF2PsDFpr1dUAv77JnpV5669HnRnULJ2Y6JkuFiS
```
<p align="center">
  <img src="./donate/silentpuck_xmr_qr.png" width="200" alt="Monero QR">
</p>

### ₿ Bitcoin (BTC)
```
bc1q7jrq0u4yu6s5jgtrwkmwjaqhttam3ch3ura4aw
```
<p align="center">
  <img src="./donate/btc_donate.png" width="200" alt="Bitcoin QR">
</p>

> 🕶 Privacy-first. No middlemen. No KYC.

---

## 🧠 Philosophy

**SilentPuck** creates tools for invisible people.  
No backdoors. No tracking. No phone home. Just code that works.

> Tools for the privacy underground.  
> 🛠 Written in C. Signed. Delivered.

---

Made with 🛠 by [**SilentPuck**](https://github.com/SilentPuck)