/*
videoConverter proj
*	modified by:		 JaydenZ
*	This program is from OpenCV 2.4 example.
*	original author:	 ethan rublee
*	description: 		convert video to a sequence of image.
*	usage: 				para can be modified in the section of CONST
						for the input, simply designate the video name. 
						for the output, will be saved in ./image...
					... the output format could be changed in the belowing box
*/

#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace cv;
using namespace std;

// ---------------------------------para here---------------------------------
// path to saved image
const string path = "image/";
// stride for saving the sequential image
const int stride = 50;
// ---------------------------------------------------------------------------

//hide the local functions in an anon namespace
namespace {
    void help(char** av) {
        cout << "\nThis program justs gets you started convert a video to a sequence of image" 
            "Usage:\n./" << av[0] << " <video device number>\n"
            << "q,Q,esc -- quit\n"
            << "space   -- save frame\n\n"
            << "\tThis is a starter sample, to get you up and going in a copy pasta fashion\n"
            << "\tThe program captures frames from a camera connected to your computer.\n"
            << "\tTo find the video device number, try ls /dev/video* \n"
            << "\tYou may also pass a video file, like my_vide.avi instead of a device number"
            << endl;
    }

    int process(VideoCapture& capture) {
        int n = 0;

		int count = 0;

        char filename[200];
        string window_name = "video | q or esc to quit";
        cout << "press space to save a picture. q or esc to quit" << endl;
        namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable window;
        Mat frame;
        for (;;) {
            capture >> frame;
            if (frame.empty())
                break;
            imshow(window_name, frame);
			count++;
			if (count == stride) {

// ---------------- the output file name can be changed below-----------
				sprintf(filename, "%7d.jpg", n++);
// ---------------------------------------------------------------------

				string filename_after(filename);					
				string filename_final;
				filename_final = path + filename;
				imwrite(filename_final, frame);
				count = 0;
			}
			char key = (char)waitKey(1);
            switch (key) {
	        case 'q':
		    case 'Q':
       		case 27: //escape key
           		return 0;
	        default:
		  	  break;
            }
        }
        return 0;
    }

}

int main(int ac, char** av) {

    if (ac != 2) {
        help(av);
        return 1;
    }
    std::string arg = av[1];
    VideoCapture capture(arg); 
    if (!capture.isOpened()); 
	{
	cout << " no such file called: " << arg <<endl;
	return 1;
	}
    return process(capture);
}
