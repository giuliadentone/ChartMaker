# ChartMaker
I developed this software by experimenting with Qt.

##Aim of the project
My main goal was to create software that elaborates and manipulates data sets to generate different types of charts.

##How to run ChartMaker
To run the project, first and foremost, it's necessary to install Qt. You can find it here. Then you can download the repository and navigate to the root of the project. After that, all you need to do is follow these commands in your terminal:

go
Copy code
qmake -qt=qt5
make
./ChartMaker
This should display the main window on your screen.

##User manual
JSON file
The software takes as input a JSON file that needs to contain labels for the data and the data itself. Here are the main rules for the input file:

Every row of the JSON file will correspond to a row of data for the table of data you will see in the view.

It can only contain integers and doubles because those are the data types I was interested in manipulating. If you desire to upgrade the source code to make it possible to use every data type, you can turn my DataMatrix class into a template class. Feel free to do so and notify me of your suggestions!

For planning purposes, I decided to take input only data sets that contain data that are already elaborated. The program will not sum data in the dataset if, for example, there are multiple rows named under the same labels. Here is an explanatory picture:

Labels are important because they will appear on the chart to make it more legible.

It is mandatory that the input file does not contain errors (such as the lack of commas or the presence of data that exceeds the number of columns established for the data set). If the data set contains errors, the software will simply crash or will not open your file.

If you want to save the data set you created by modifying the table directly on the view (as I will explain later), the JSON file that is going to be saved on your computer will be in the format previously shown.

Here are some prepared JSON files to play with the ChartMaker or to take inspiration for your dataset:

##Development environment
Operating system: Ubuntu 20.10 64-bit
Qt version: 5.9.5"
