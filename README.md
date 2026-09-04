# rxDSA
A standalone and lightweight C algorithms library

## 📦 Installation

Choose the native package manager for your operating system:

### 🍏 macOS & Linux (Homebrew)
```bash
brew tap rookie2373/rxdsa
brew install librxdsa
```

### 🦅 Arch Linux (Pacman / AUR)
```bash
yay -S librxdsa
# or
paru -S librxdsa
```

### 🐳 Ubuntu & Debian (APT)
Download the `.deb` asset from our [Releases page](https://github.com) and install natively:
```bash
sudo apt update
sudo apt install ./librxdsa-0.0.19-amd64.deb
```

### 🎩 Fedora & RedHat (DNF)
Download the `.rpm` asset from our [Releases page](https://github.com) and install natively:
```bash
sudo dnf install ./librxdsa-0.0.19-1.x86_64.rpm
```

### 🪟 Windows (MinGW-w64)
Download `librxdsa-0.0.19.zip` from our Releases page and link the static library inside your workspace path:
```bash
# Include Paths
-Iinclude/rxdsa

# Linker Flags
-L. -lrxdsa
```