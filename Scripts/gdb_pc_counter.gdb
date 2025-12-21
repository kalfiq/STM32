set pagination off

#file build/firmware.elf
file cmake_build/test.elf

target remote localhost:3333
load

set $count = 0
while $pc != &main
  stepi
  set $count++
end

print $count
