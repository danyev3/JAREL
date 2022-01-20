# JAREL Arduino Library
## Just Another Rotary Encoder Library
&nbsp;
### About JAREL 
JAREL is a fork of [MPrograms](https://github.com/mprograms/)'s [SimpleRotary](https://github.com/mprograms/SimpleRotary/) Arduino Encoder library, aiming to add more functionality to an already great library.
Refer to SimpleRotary's [README](https://github.com/mprograms/SimpleRotary/blob/master/readme.md) and [examples](https://https://github.com/mprograms/SimpleRotary/tree/master/examples) for all info on the base usage of the library.

### Features added on top of SimpleRotary:
- Position system for every encoder, accessible via the `jarel.position` parameter. `jarel.lastPosition` is also available and contains the value of `jarel.position` in the last loop.
- The definition of a `jarel` object now accepts the **optional** parameters `positionDefault`, `limited`, `positionMin`, `positionMax` and `steps`, in this order.
	- `positionDefault` is an public integer that sets the default `jarel.position` when the program starts (default value `0`)
	- `limited` is a boolean that enables the upper and lower limits of `jarel.position` (default value `false`)
	- `positionMin` and `positionMax` are public integers that set the upper and lower limits of `jarel.position` when `limited` is set to `true` (default values `0` and `100`) 
	- `steps` is how many positions will increase/decrease for each encoder click, if `limited` is set to `true` this should be a multiple of `positionDefault`, `positionMin` and `positionMax` or your position will get out of phase when it reaches the limits (default value `1`)
- The position can be manually controlled via the `setPosition`, `resetPosition`, `increasePosition` and `decreasePosition` methods:
	- `setPosition` takes an integer and sets it as the current `jarel.position`, updating `jarel.lastPosition` in the process
	- `resetPosition` takes no arguments and resets `jarel.position` to `jarel.positionDefault`
	- `increasePosition` and `decreasePosition` take an integer argument and respectively increase and decrease `jarel.position` by the passed integer, if no parameter is passed, it will increase or decrease by 1
- The position system can be deactivated and reactivated using `jarel.disable()` and `jarel.enable`, these methods will change the `jarel.enabled` public boolean parameter

### Todo:
- Add wrap-around option when the limits are turned on
- Add reverse direction option