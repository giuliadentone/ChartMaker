# _ChartMaker
I developed this software by experimenting with Qt.

## Aim of the project
My main goal was to create a software that elaborates and manipolates data sets to generates different types of charts.

## How to run ChartMaker
To run the project first and foremost it's necessary to install Qt. You can find it [here](https://www.qt.io/download).
Then you can download the repository and navigate to the root of the project. After that all you need to do is thow those commands in your terminal:
- qmake -qt = qt5 
- make
- ./Chartmaker
This should show the main window on your screen.

## User manual
### Json file
The software takes in input a JSON file that needs to contain labels for the data and the data itself. Here are the main rules for the input file:
- Every row of the JSON file will correspond to a row of data for the table of data you will see in the view.
- It can oly contain integers and doubles because those are the data types i was interested in manupulating. If you desire to upgrade the source code to make it possible to use every data type you can turn my DataMatrix class to a template class. Feel free to do so and notify me your suggesions!
- For planning purposes I decided to take in input only data sets that contain datas that are already elabourated. The program will not sum data in the dataset if for example there are multiple rows named under the same labels. Here is an explanation picture:

- Labels are important because they will appear on the chart to make it more legible. 
- It is mandatory that the input file does not contain errors (such as the lack of commas or or the presence of datas that exceed the number of columns established for the data set). If the data set contains errors the software simply will crush or will not open your file.
- If you want to save the data set you created by modifying the table directly on the view (as I will explain later) the JSON file that is going to be saved in your computer will be in the format previously shown.

Here are some prepared JSON files to play with the ChartMaker or to take inspiration for your own dataset:


### Main interface

## Development environment
- Operating system: Ubuntu 20.10 64-bit
- Qt version: 5.9.5


