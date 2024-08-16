package com.demo;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.PersistableBundle;


public class DemoActivity extends AppCompatActivity {
    static {
        System.loadLibrary("democore");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        android.util.Log.i("hanszhli", "oncreate");
    }
}
