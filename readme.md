# JAREL Arduino Library
#### Just Another Rotary Encoder Library

JAREL is a fork of [MPrograms](https://github.com/mprograms/)'s [SimpleRotary](https://github.com/mprograms/SimpleRotary/) Arduino Encoder library, aiming to add more functionality to an already great library.
Refer to SimpleRotary's [README](https://github.com/mprograms/SimpleRotary/blob/master/readme.md) and [examples](https://https://github.com/mprograms/SimpleRotary/tree/master/examples) for all info on the base usage of the library.


#### Features added on top of SimpleRotary:
- Position system for every encoder, accessible via the `jarel.position` parameter. `jarel.lastPosition` is also available and contains the value of `jarel.position` in the last loop.
- The definition of a `jarel` object now accepts the **optional** parameters `positionDefault`, `limited`, `positionMin`, `positionMax` and `steps`, in this order.
  - `positionDefault` is an public integer that sets the default position of the encoder when the program starts (default value `0`)
  - `limited` is a boolean that enables the upper and lower limits of the encoder position (default value `false`)
  - `positionMin` and `positionMax` are public integers that set the upper and lower limit of the encoder position when `limited` is set to `true` (default values `0` and `100`) 
  - `steps` is how many positions will increase/decrease for each encoder click, if `limited` is set to `true` this should be a multiple of `positionDefault`, `positionMin` and `positionMax` as to not go over or under the limits (default value `1`) 
- The position system can be deactivated and reactivated using `jarel.disable()` and `jarel.enable`, these methods will change the `jarel.enabled` boolean parameter