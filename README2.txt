http://mike.ucoz.com/publ/programming/ubuntu/selenium_ubuntu_amazon_ec2_headless/8-1-0-4

http://mike.ucoz.com/publ/programming/ubuntu/selenium_ubuntu_amazon_ec2_headless/8-1-0-4

pip install https://storage.googleapis.com/tensorflow/linux/cpu/tensorflow-0.5.0-cp27-none-linux_x86_64.whl


sudo apt-get update
sudo apt-get install python-pip
sudo pip install selenium


Install headless java
sudo apt-get install openjdk-6-jre-headless

Fonts
sudo apt-get install xfonts-100dpi xfonts-75dpi xfonts-scalable xfonts-cyrillic

Headless X11 magic is here
sudo apt-get install xvfb

We still demand X11 core
sudo apt-get install xserver-xorg-core

Firefox installation
sudo apt-get install firefox

Download Selenium server
wget http://selenium.googlecode.com/files/selenium-server-standalone-2.31.0.jar

Enjoyment

Run Selenium server 
Xvfb :0 -screen 0 1024x768x24 2>&1 >/dev/null &
export DISPLAY=:0
nohup xvfb-run java -jar selenium-server-standalone-2.31.0.jar > selenium.log &

