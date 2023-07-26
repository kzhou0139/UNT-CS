#Kelly Zhou
#ksz0009

{if (NR == 1 && !/Degrees/)
  exit 1
remainder = $1%360
if (remainder >= 0 && remainder < 360)
  coterminal = remainder
else
  coterminal = remainder + 360
if (NR != 1)
  print $1 "\t" coterminal}
