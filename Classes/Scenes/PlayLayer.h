#ifndef __PlayLayer_H__
#define __PlayLayer_H__

#include "cocos2d.h"

USING_NS_CC;

class SushiSprite;

class PlayLayer : public Layer
{
public:
    PlayLayer();
    ~PlayLayer();
    static Scene* createScene();
    CREATE_FUNC(PlayLayer);
    
    virtual bool init() override;
private:
    SpriteBatchNode *spriteSheet;
    SushiSprite **m_matrix;
    int m_width;
    int m_height;
    float m_matrixLeftBottomX;
    float m_matrixLeftBottomY;
    
    void initMatrix();
    void createAndDropSushi(int row, int col);
    Point positionOfItem(int row, int col);
};

#endif /* defined(__PlayLayer_H__) */
