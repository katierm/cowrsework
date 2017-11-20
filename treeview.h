#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

#include "codetree1.h"
#include "codetree.h"
class TreeView : public QWidget{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(code_tree::BT* data);
    void setTree(CodeTree* data);

protected:
    void paintEvent(QPaintEvent *event) override;
    //void DynpaintEvent(QPaintEvent *event) ;

private:
    void drawNode(QPainter *painter, const CodeTree* root, int x, int y);
    void drawNode(QPainter *painter, const code_tree:: BT* root, int x, int y);
    const CodeTree* tree;
    code_tree::BT* tree_dyn;
    const int nodeWidth{ 80 };
    const int nodeHeight{ 80 };
    bool dynamic;
};

#endif // TREEVIEW_H
