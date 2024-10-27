#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
using namespace std;

    // I'm working on projects and not sure if I need to do this homework, but still did it
    // I'm sorry for being late.
    // not fully implemented, not wokring: sphere generation, cutting functionality




class Object3d {

    private:
    string filePath;
    ifstream currentFile;
    string data;
 
    public:
    //this should be private :P
   Object3d(string data,int a){
        this->data = data;
    }

    Object3d(string filePath){
        this->filePath = filePath;
        currentFile.open(filePath);
        if(!currentFile.good()){
            throw invalid_argument("Problem opening file");
        }
         string line;

        while( getline(currentFile,line) ) {
            data.append(line + '\n');
        }

    }
    // TODO: Init from stream;
    Object3d(ifstream& strm){
     //   this->currentFile = strm;
    }

    ~Object3d(){
        currentFile.close();
    }

    int getVertexCount()
    {
        int vertextCount;
        string line;

        while( getline(currentFile,line) ) {
            if(line[0] == 'v')vertextCount++;
        }

        return vertextCount;
    
    }
    int getFaceCount()   {
        int faceCount;
        string line;

        while( getline(currentFile,line) ) {
            if(line[0] == 'f') faceCount++;
        }

        return faceCount;
    
    }
    void save(const string& file){
        ofstream output(file);
        if(!output.good()) throw invalid_argument("cannot save file");
        output << data;
        output.close();
    }
    void print(ostream& os){

        if(!os.good()){
            throw invalid_argument("Cannot display information in this stream");
        }
        os << data;
    }

    Object3d cut(function<bool(float x, float y, float z)> f){


        // the flip function was is easy, so I thought i can just copy and paste
        // couldn't replicate the image from example code given
        // couldn't even cut the cube manually to test the functionality
        // maybe windows 10 3d viewer problem, I don't know.
        // everything else is tested and should work


       throw invalid_argument("Cannot cut, because cannot replicate, Check code for more info");

        //check code below to see possible implementation





         string line;
        string newData;

      //  ! this is new

        vector<int> removedV;
        int count;


        for (int  i =0 ;i<data.size();i++){

            if(data[i] == '\n'){
                if(line[1] == 'v'){

             //   ======= counting vertices
                    count++;
             //   ========
                    int index=0;
                     vector<string> lineData;
                     string localdata;
                   for(int k =0;k<=line.size();k++){

                    if(line[k] == ' ' || k == line.size()){
                        lineData.push_back(localdata);
                        localdata = "";
                        continue;
                    }
                        localdata+= line[k];
                   }
                    string toPush;
                    if(f(stof(lineData[1]),stof(lineData[2]),stof(lineData[3]))){

                   //cannot write on the same line
                     toPush += line[1];
                    toPush += " ";
                     toPush += lineData[1];
                    toPush += " ";
                     toPush += lineData[2];
                    toPush += " ";
                     toPush += lineData[3];
                     toPush += "\n";
                    }else{
                        removedV.push_back(count);
                    }
                    
                    newData += toPush; //+ localdata[0]);
                }else{
                    newData += line;
                }


                line = "";
            }
            line += data[i];
        }
    for (int  i =0 ;i<data.size();i++){

            if(data[i] == '\n'){
                if(line[1] == 'f'){
                     int index=0;
                     vector<string> lineData;
                     string localdata;
                   for(int k =0;k<=line.size();k++){

                    if(line[k] == ' ' || k == line.size()){
                        lineData.push_back(localdata);
                        localdata = "";
                        continue;
                    }
                        localdata+= line[k];
                   }
                    string toPush;
                    if(std::find(removedV.begin(), removedV.end(), stof(lineData[1]))== removedV.end()){
                    if(std::find(removedV.begin(), removedV.end(), stof(lineData[2]))== removedV.end()){
                    if(std::find(removedV.begin(), removedV.end(), stof(lineData[3]))== removedV.end()){
                    if(std::find(removedV.begin(), removedV.end(), stof(lineData[4]))== removedV.end()){
                
                   //cannot write on the same line
                     toPush += line[1];
                    toPush += " ";
                     toPush += lineData[1];
                    toPush += " ";
                     toPush += lineData[2];
                    toPush += " ";
                     toPush += lineData[3];
                     toPush += "\n";
                    }
                    }
                    }
                    }
              
                   newData += toPush; //+ localdata[0]);
                }


               line = "";
            }
           line += data[i];
        }

       return Object3d(newData,1);
    }
    void flip(){
        
        string line;
        string newData;
        for (int  i =0 ;i<data.size();i++){

            if(data[i] == '\n'){
                if(line[1] == 'v'){
                    int index=0;
                     vector<string> lineData;
                     string localdata;
                   for(int k =0;k<=line.size();k++){

                    if(line[k] == ' ' || k == line.size()){
                        lineData.push_back(localdata);
                        localdata = "";
                        continue;
                    }
                        localdata+= line[k];
                   }

                   //cannot write on the same line
                    string toPush;
                     toPush += line[1];
                    toPush += " ";
                     toPush += lineData[3];
                    toPush += " ";
                     toPush += lineData[2];
                    toPush += " ";
                     toPush += lineData[1];
                     toPush += "\n";
                    newData += toPush; //+ localdata[0]);
                }else{
                    newData += line;
                }


                line = "";
            }
            line += data[i];

        }
        this->data = newData;

        // ! library not allowed <sstream>
    
        // std::istringstream iss(data);

        // for (std::string line; std::getline(data, line); )
        // {
        //     if(line[0] == 'f'){
        //         result += ">> " + line + "\n";
        //     }
        // }

    
    }


};

void Sphere(float size){
    //https://gamedev.stackexchange.com/questions/16585/how-do-you-programmatically-generate-a-sphere
    //no time for implementation
    throw invalid_argument("no time for implementation");
}

Object3d Cube(float size){

    //lazy implementation, I know

    string data;
    data += "# vertices";
    data += "\n";
    data += "v "+ to_string(-1 *size) + " "+ to_string(-1*size )+ " " + to_string(size* -1);
    data += "\n";
    data += "v "+ to_string(1 *size )+ " "+  to_string(-1  *size) + " "+ to_string(size*-1);
    data += "\n";
    data += "v "+ to_string(1  *size) + " "+ to_string(-1  *size )+ " "+ to_string(size* 1);
    data += "\n";
    data += "v "+ to_string(-1 *size) + " "+ to_string( -1  *size )+ " "+to_string(size*  1);
    data += "\n";
    data += "v "+ to_string(-1  *size) + " "+ to_string( 1  *size )+ " "+to_string(size* -1);
    data += "\n";
    data += "v "+ to_string( 1  *size) + " "+ to_string( 1 *size )+ " "+ to_string(size* -1);
    data += "\n";
    data += "v " +to_string( 1  *size) + " "+ to_string( 1 *size )+ " "+to_string(size*   1);
    data += "\n";
    data += "v "+ to_string(-1 *size) + " "+  to_string( 1  *size )+ " "+to_string(size*  1);
    data += "\n";
    data += "# faces";
    data += "\n";
    data += "f 1 2 3 4";
    data += "\n";
    data += "f 8 7 6 5";
    data += "\n";
    data += "f 1 5 6 2";
    data += "\n";
    data += "f 2 6 7 3";
    data += "\n";
    data += "f 3 7 8 4";
    data += "\n";
    data += "f 4 8 5 1";
    data += "\n";
//   ofstream output(file);
//         if(!output.good()) throw invalid_argument("cannot save file");
//         output << data;
//         output.close();
   return  Object3d(data,1);
    
}


int main(){

    Object3d cuber= Cube(3);
    cuber.save("deeznuts.obj");
    return 0;
}