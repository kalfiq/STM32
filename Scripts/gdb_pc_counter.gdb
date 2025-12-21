set pagination off

#file build/firmware.elf
file Release/firmware.elf

target remote localhost:3333
load

set $count = 0
while $pc != &main
  stepi
  set $count++
end

print $count
