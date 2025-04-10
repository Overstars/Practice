package com.example.androidcompose.layout

import android.util.Log
import androidx.compose.foundation.layout.Column
import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.platform.LocalLifecycleOwner
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.Lifecycle
import androidx.lifecycle.Lifecycle.Event.*
import androidx.lifecycle.LifecycleEventObserver

@Composable
fun LifecycleSample() {
    var count by remember {
        mutableStateOf(0)
    }
    val lifecycleOwner = LocalLifecycleOwner.current
    DisposableEffect(lifecycleOwner) {
        Log.i("=====", "LifecycleSample: DisposableEffect")
        val lifecycleEventObserver = LifecycleEventObserver { _, event ->
            Log.i("=====", "LifecycleSample: DisposableEffect LifecycleEventObserver $event")
            when (event) {
                ON_PAUSE -> {
                    // 进入后台，调用暂停方法
                }
                ON_RESUME -> {
                    // 从后台回到前台，调用恢复方法
                }

                ON_CREATE -> TODO()
                ON_START -> TODO()
                ON_STOP -> TODO()
                ON_DESTROY -> TODO()
                ON_ANY -> TODO()
            }
        }
        onDispose {
            lifecycleOwner.lifecycle.removeObserver(lifecycleEventObserver)
        }
    }
    LaunchedEffect(count) {
        Log.i("=====", "LifecycleSample: LaunchedEffect")
    }
    Log.i("=====", "LifecycleSample: LaunchedEffect2")
    Column() {
        Text(text = "LifecycleSample")
        Button(onClick = {
            count++
        }) {
            Text(text = "Button count: $count")
        }
        if (count == 3) {
           LifecycleSample2(count)
        }
    }
}

@Composable
fun LifecycleSample2(count: Int) {
//    var count by remember {
//        mutableStateOf(0)
//    }

    DisposableEffect(Unit) {
        Log.i("=====", "LifecycleSample2: DisposableEffect")
        onDispose {
            Log.i("=====", "LifecycleSample2: DisposableEffect onDispose")
        }
    }
    Log.i("=====", "LifecycleSample2: DisposableEffect2")

    Text(text = "恭喜砂了${count}个仁仁")
}

@Preview
@Composable
fun LifecycleSamplePreview() {
    LifecycleSample()
}