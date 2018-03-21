package com.malepati.vikas.ftcsimulation.math;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class Vector2f {

    public float x, y;

    public Vector2f() {
        set(0.0f, 0.0f);
    }

    public Vector2f(Vector2f vector) {
        set(vector.x, vector.y);
    }

    public Vector2f(float x, float y) {
        set(x, y);
    }

    public void set(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public Vector2f add(Vector2f vector) {
        this.x += vector.x;
        this.y += vector.y;
        return this;
    }

    public Vector2f subtract(Vector2f vector) {
        this.x -= vector.x;
        this.y -= vector.y;
        return this;
    }

    public Vector2f multiply(Vector2f vector) {
        this.x *= vector.x;
        this.y *= vector.y;
        return this;
    }

    public Vector2f divide(Vector2f vector) {
        this.x /= vector.x;
        this.y /= vector.y;
        return this;
    }

    public float getMagnitude() {
        return (float) Math.sqrt(x * x + y * y);
    }

    public Vector2f getNormalized() {
        float length = getMagnitude();
        return new Vector2f(x / length, y / length);
    }

    public static float getDistance(Vector2f v0, Vector2f v1) {
        double x = v0.getX() - v1.getX();
        double y = v0.getY() - v1.getY();
        return (float) Math.sqrt(x * x + y * y);
    }

    public static float getDot(Vector2f v0, Vector2f v1) {
        return v0.x * v1.x + v0.y * v1.y;
    }

    public boolean equals(Object object) {
        if (!(object instanceof Vector2f)) return false;
        Vector2f vec = (Vector2f) object;
        if (vec.getX() == this.getX() && vec.getY() == this.getY()) return true;
        return false;
    }
}
