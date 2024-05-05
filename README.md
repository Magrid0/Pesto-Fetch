# Pesto Fetch

This C++ program retrieves and displays basic system information such as hostname, username, Linux distribution (distro), and CPU details.

## Usage

1. **Compile the Program:** Use a C++ compiler to compile the program. For example, you can use g++:
`g++ main.cpp -o Pesto-Fetch`

2. **Run the Program:** Execute the compiled binary to display system information:
`./Pesto-Fetch`

## Example Output

```
magrid@desktop

Distro: Arch Linux
CPU: AMD Ryzen 5 5600G with Integrated Radeon Graphics
```

## Note
- The program assumes Linux environment for retrieving system information.
- Make sure the program has necessary permissions to read system files such as `/etc/hostname`, `/etc/os-release`, and `/proc/cpuinfo`.
