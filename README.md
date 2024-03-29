# ChartMaker
ChartMaker is a data visualization software developed using the Qt framework. This project aims to create a tool that can manipulate and generate various types of charts from data sets.

## How to Run ChartMaker
Before running the project, you must install Qt, which can be downloaded here. Once Qt is installed, follow these steps to run ChartMaker:

Clone or download this repository to your local machine.
Navigate to the root directory of the project using your terminal.
Execute the following commands: <br>
qmake -qt=qt5 <br>
make <br>
./ChartMaker <br>

This will launch the ChartMaker application, displaying the main window on your screen.

## User Manual:
JSON Input
ChartMaker requires a JSON input file that contains labels for the data and the data itself. Here are the key rules for the input file:

Each row of the JSON file corresponds to a row of data in the table view.
The data in the JSON file should consist of integers and doubles only, as these are the supported data types. If you wish to expand the software to handle other data types, you can modify the DataMatrix class accordingly. Feel free to make improvements and share your suggestions!
For optimal results, the input data sets should be preprocessed and error-free. The program does not perform data aggregation; it assumes that the data in the dataset is already elaborated. Avoid having multiple rows with the same labels, as this can lead to confusion in the generated charts.

Labels are crucial as they are used to enhance the legibility of the charts.

Please ensure that your input file is free of errors, such as missing commas or data exceeding the predefined number of columns. If your data set contains errors, the software may crash or fail to open your file.

If you wish to save the modified data set by directly editing the table view (as explained later), the saved JSON file will adhere to the format previously specified.

Clicking on "New" brings up a window where you can input a label for the row, and once confirmed, a label for the column will appear. At this point, the table will appear in the view and can be edited as desired by the user.

In the Menu Bar under the "Edit" section, you can find the following functionalities:

"Add column before/add row before"
"Add column after/add row after"
"Delete column/delete row"
Simply select a cell belonging to the desired row/column and click on the menu item.
To edit an individual data point, simply double-click on the desired cell and then press Enter. The chart will be updated automatically.


On the other hand, by clicking on "Open," you can input a JSON file into the program. Once you do that, the table with the data from the file will be created and displayed in the view.

In the Menu Bar under the "File" section, you will find the following functionalities:

"New" allows you to create a new table by inputting labels for the rows and columns. The view will display the new table, and you will need to draw a new chart of your choice to represent the updated dataset.
"Open" enables you to open a .json file from your device, and the program will automatically display the table with the new dataset in the view.
"Save" allows you to save the dataset of the created or modified table currently displayed in the view to a new JSON file.
"Save as PNG" lets you save the chart in PNG format. Simply choose a name for the file, and if it doesn't save to your device automatically, manually add ".png" after the chosen file name. To adjust its size, you can enlarge or shrink the window.
"Save as PDF" allows you to save the chart in PDF format.
"Exit" closes the window.

To display the desired chart in the view, you need to click on "View." A dropdown menu will appear with all available charts:
- Pie Chart
- Donut Chart
- Bar Chart
- Stacked Bar Chart
- Horizontal Bar Chart
- Horizontal Stacked Bar Chart
- Percent Bar Chart
- Horizontal Percent Bar Chart
- Line Chart
- Spline Chart
- Scatter Chart

If you choose to generate a Pie Chart or a Donut Chart, the program will open a warning window notifying the user that these charts, as explained earlier, only consider the first data column.

## Development Environment
Operating System: Ubuntu 20.10 64-bit<br>
Qt Version: 5.9.5 <br>

Feel free to explore and enhance ChartMaker for your data visualization needs. If you make improvements or have suggestions, please don't hesitate to reach out and share your feedback. Happy charting!
