#include <stdio.h>
#include <math.h>

struct type_f
{
    double x1;
    double x2;
};

struct type_f decide_float(float delta)
{
    struct type_f answer_f;
    answer_f.x2 = (2.0001f + delta - 2) / 0.0001f ;
    answer_f.x1 = 2.0000f - answer_f.x2;

    return answer_f;
}

struct type_d
{
    float x1;
    float x2;
};

struct type_d decide_double(double delta)
{
    struct type_d answer_d;
    answer_d.x2 = (2.0001 + delta - 2) / 0.0001;
    answer_d.x1 = 2.0000 - answer_d.x2;

    return answer_d;
}

float distance_f(struct type_f p1 , struct type_f p2)
{
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

double distance_d(struct type_d p1 , struct type_d p2)
{
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

int main() {
    float float_delta = 0.0000f;
    double double_delta = 0.0000;


    printf("Float_delta = %.20f", float_delta);
    printf("\n Double_delta= %.20lf", double_delta);

    struct type_d double_points = decide_double(double_delta);
    struct type_f float_points = decide_float(float_delta);

    printf("\n double_point: x1 = %.20lf x2 = %.20lf", double_points.x1, double_points.x2);
    printf("\n float_point: x1 = %.20f x2 = %.20f", float_points.x1, float_points.x2);

    float distance_f_points;
    double distance_d_points;
    int step = 1;

    float_delta = 0.00001f;
    double_delta = 0.00001;
    do
    {
        printf("\n\n ############### Test [%d] ###############" , step);
        struct type_d new_double_points = decide_double(double_delta);
        struct type_f new_float_points = decide_float(float_delta);

        distance_d_points = distance_d(double_points , new_double_points);
        distance_f_points = distance_f(float_points , new_float_points);

        printf("\n )double_delta = %.20lf" , double_delta);
        printf("\n )New double points:x1 = %.20lf \n | x2 = %.20lf" , new_double_points.x1 , new_double_points.x2);
        printf("\n )distance_d = %.20lf" , distance_d);

        printf("\n\n ]float_delta= %.20f" , float_delta);
        printf("\n ]new float points: x1 = %.20f \n () x2 = %.20f" , new_float_points.x1 , new_float_points.x2);
        printf("\n ]distance_f = %.20f" , distance_f);


        double_delta /= 2.000;
        float_delta /= 2.000f;
        ++step;
    } while ((distance_d_points > 0) || (distance_f_points > 0.000001f));
}
