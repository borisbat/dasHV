# dasHV - bindings for HV - cross platform network library

## PREREQUISITES:
- **OpenSSL** (works with `3.5.1`)

## Installation:

### Linux (Debian/Ubuntu):
```bash
sudo apt update
sudo apt install openssl=3.*
```

### macOS (Homebrew):
```bash
brew install openssl@3
```

### Windows:
Using official installer:
- For x86-64 download 3.5.1 installer from https://slproweb.com/products/Win64OpenSSL.html
- For x86 download 3.5.1 installer from https://slproweb.com/products/Win32OpenSSL.html

Or via vcpkg:
```powershell
vcpkg install openssl:x64-windows --version=3.5.1 # for x86-64
vcpkg install openssl:x86-windows --version=3.5.1 # for x86
```
