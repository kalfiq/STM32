# Starting the session
## Start an OpenOCD session
```
openocd -f <config file> -s "/usr/share/openocd/scripts"
```

## Start a debugging session
### Telnet method
```
telnet 127.0.0.1 4444
```

### GDB method
```
gdb-multiarch <file name>.elf
target remote localhost:3333  # Connect GDB client to port 3333 of OpenOCD server
monitor reset halt            # Reset and halt the MCU

load                          # Can also be used to restart the debugging session
```

# Debugging notes
The commands shown below should be run in the gdb console.

## Printing function name
```
print &function_name
```

## Printing stack pointer
```
print /x $sp    # Print the value stored by the stack pointer in hex
x/40x $sp       # Print the first 40 words of memory after the start of current function stack
```

## Printing variable values
```
print &_sdata   # Print the address of _sdata
print _sdata    # Print the value stored by _sdata
```

## Restart session
```
load
```
