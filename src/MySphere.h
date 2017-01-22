//
//  MySphere.h
//  emptyExample
//
//  Created by 大林巧 on 2017/01/19.
//
//

#ifndef _MY_SPHERE/* ユニークな名前 */ //インクルードガード
#define _MY_SPHERE/* ユニークな名前 */

#include "ofMain.h" //ofMain.hをインクルード
class MySphere{ //クラスの開始
    
public:
    //公開のプロパティ、メソッドを宣言する
    MySphere();
    void update();
    void draw();
    
    void setPos(ofPoint pos);
    ofPoint getPos();
    
private:
    //非公開のプロパティ、メソッドを宣言する
    ofSpherePrimitive sphere; // 球プリミティブ
    float radius;
    float counter;
    ofPoint pos;
    
}; //セミコロンを忘れずに!!

#endif //インクルードガードの終了