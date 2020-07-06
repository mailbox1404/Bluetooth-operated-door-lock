# Bluetooth-operated-door-lock
Here you will find all the files required for this project.

[OLD] Watch the tutorial video at-
https://youtu.be/at00y2N-u3A

Download the app from-
https://play.google.com/store/apps/details?id=com.rupak.smart_lock

Carrying keys has always been a hastle. It's a responsibility to keep them safely. But everybody carries phone while going out. What if I say that instead of keys, you can unlock the door with your smartphone via bluetooth. Simply enter the password on your smartphone and walk in!

-What if you misplace your phone?

  No one can get into your house using your phone because the intruder needs to enter a password inside the app.
 
-How will you get in if you misplace your phone?

  Simply borrow a phone from someone for a second, download the app from Google Play Store, connect to the right bluetooth device, enter the password and walk in!


# Parts required:
- HC05 Bluetooth Module
- Arduino board
- Electronic lock
- Relay module
- Power adapter
- Some jumper cables

# Build the circuit
Step 1: Upload the Smart lock code to your Arduino board. You can find the code here- https://github.com/Rupakpoddar/Bluetooth-operated-door-lock/blob/master/Smart_lock/Smart_lock.ino

Step 2: Attach a Bluetooth module and connect an electronic door lock to the pin number 12 of the Arduino board using a relay module as shown in the picture.

[HERE COMES THE IMAGE]

Step 3: Turn on the system. Go to the Bluetooth settings on your phone and pair your Bluetooth module.

Step 4: Download the Smart lock app from Google Play Store. You may use the link mentioned above. Open the app and Click the "Click here to connect" button and select your Bluetooth module.

Step 5: Go to the setup page and click the "Change password" button. Leave the current password column blank for the first time. Enter and confirm the new password and again hit the "Change password" button.

For now you are done. You may tinker around with the settings on the setup page.

# Details
## The Android app and the Arduino code makes use of the Arduino EEPROM to store the password. The password remains in the memory even if the Arduino board is turned off. If you forget the password by any chance, you cannot reset it by uploading the Arduino code again. In this case, if you want to reset your password, you need to flash the Reset_EEPROM code to your Arduino board. You can find the code here- https://github.com/Rupakpoddar/Bluetooth-operated-door-lock/blob/master/Reset_EEPROM/Reset_EEPROM.ino.
