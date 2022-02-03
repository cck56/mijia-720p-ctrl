# Mijia 720p control

The code controls the pan/tilt motors of Mijia 720p 360 degree version, and includes control of IR cut filter, IR led, ISP daynight mode and LED indicator. UDP server is set up to receive commands.

### Example

#### Motor

```bash
# echo -n "MOVE,[xsteps],[ysteps]" | nc -4u -q1 [camera-ip] 8888
```

Moves the motors relatively by number of steps, returns the absolution position:
motor x: 0 to 31
motor y: 0 to 15

#### IR LED

```bash
# echo -n "IRLED,[val]" | nc -4u -q1 [camera-ip] 8888
```

Set the brightness of IR LED, value ranges from 0 to 255

#### IR-cut filter

```bash
# echo -n "IRCUT,[val]" | nc -4u -q1 [camera-ip] 8888
```

0: turns off IR-cut filter
1: turns on IR-cut filter

#### DAYNIGHT mode

```bash
# echo -n "DAYNIGHT,[val]" | nc -4u -q1 [camera-ip] 8888
```

0: color video output
1: grayscale video output

#### LEDSTATUS

```bash
# echo -n "LEDSTATUS,[led],[val]" | nc -4u -q1 [camera-ip] 8888
```

led: 0 = blue, 1 = orange
val: 0 = on, 1 = off, 2 = blink


#### GETSTAT

```bash
# echo -n "GETSTAT" | nc -4u -q1 [camera-ip] 8888
```

returns the EV and IR(g_bg_ratio) values

#### GETEV

```bash
 # echo -n "GETEV" | nc -4u -q1 [camera-ip] 888
```

returns the EV value, this is handy to implement an external "automatic daynight" script, for example:

```bash
#!/bin/sh

IP=$1

dnfile=/tmp/DAYNIGHT
[ ! -f $dnfile ] && echo 1 >$dnfile
trigger=2500

q() {
        echo "${1}"|nc -w1 -4u ${IP} 8888
}

while :
do
        DAYNIGHT=$(cat "$dnfile")
        eval $(q "GETEV"|grep 'EV=')
        echo "EV=$EV - DAYNIGHT=$DAYNIGHT"
        if [ $EV -lt $trigger ] && [ $DAYNIGHT -eq "0" ]; then
                echo "entering night mode"
                q "DAYNIGHT,1"
                q "IRCUT,0"
                q "IRLED,255"
                echo 1 >$dnfile
        elif [ $EV -gt $trigger ] && [ $DAYNIGHT -eq "1" ]; then
                echo "leave night mode"
                q "DAYNIGHT,0"
                q "IRCUT,1"
                q "IRLED,0"
                echo 0 >$dnfile
        fi
        sleep 3
done
```
