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

To help you get started, we have included some sample JSON files for you to experiment with or gain inspiration for your datasets.

## Development Environment
Operating System: Ubuntu 20.10 64-bit<br>
Qt Version: 5.9.5 <br>

Feel free to explore and enhance ChartMaker for your data visualization needs. If you make improvements or have suggestions, please don't hesitate to reach out and share your feedback. Happy charting!
