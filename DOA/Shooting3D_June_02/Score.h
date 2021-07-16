#ifndef SCORE_H_
#define SCORE_H_

// �X�R�A�N���X
class Score {
public:
    // �R���X�g���N�^
    Score(int score = 0);
    // �X�R�A�̏�����
    void initialize(int score = 0);
    // �X�R�A�̉��Z
    void add(int score);
    // �X�R�A�̕`��
    void draw() const;
    // �X�R�A�̎擾
    int get() const;
    // �X�R�A�̃N���A
    void clear();

private:
    // �X�R�A
    int score_;
};

#endif

