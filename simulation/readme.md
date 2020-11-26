

note: this code come from algorithmic animation, a class I taught at parsons.  See "algo2012" repo.  It's been modified / updated for more modern OF

if it's helpful, the code was generally modernized  (on osx) using the following commands 

- find . -type f -iname "testApp.h" -exec rename 's/testApp/ofApp/' {} \;
- find . -type f -iname "testApp.cpp" -exec rename 's/testApp/ofApp/' {} \;\n
- find . -type f -iname "ofApp.h" -exec sed -i "" 's/testApp/ofApp/g' {} \;
- find . -type f -iname "ofApp.cpp" -exec sed -i "" 's/testApp/ofApp/g' {} \;
- find . -type f -iname "main.cpp" -exec sed -i "" 's/testApp/ofApp/g' {} \;
- grep -ilr 'ofVec2f' * | xargs -I@ sed -i '' 's/ofVec2f/ofPoint/g' @
- grep -ilr 'ofSimpleApp' * | xargs -I@ sed -i '' 's/ofSimpleApp/ofBaseApp/g' @
- grep -ilr 'ofAppGlutWindow window;' * | xargs -I@ sed -i '' 's/ofAppGlutWindow window;//g' @
- grep -ilr 'ofSetupOpenGL(&window,' * | xargs -I@ sed -i '' 's/ofSetupOpenGL(&window,/ofSetupOpenGL(/g' @
- change .grabFrame() and .idleFrame() to update()
- change .getPixels() to .getPixels().getData()
- change line.rotate(90) to line.rotate(90, ofPoint(0,0,1))
- grep -ilr 'ofSetColor(0x000000);' * | xargs -I@ sed -i '' 's/ofSetColor(0x000000);/ofSetColor(0);/g' @
- added ofBackground(180,180,180); on many examples, since the default background was too dark
- hand changed flocking example to use ofxGui

todo

- video files don't play (video examples broken) 
