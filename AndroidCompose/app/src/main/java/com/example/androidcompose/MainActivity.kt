package com.example.androidcompose

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.text.ClickableText
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.SpanStyle
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.text.buildAnnotatedString
import androidx.compose.ui.text.style.TextDecoration
import androidx.compose.ui.text.withStyle
import androidx.compose.ui.tooling.preview.Preview
import com.example.androidcompose.components.*
import com.example.androidcompose.layout.ColumnSamplePreview
import com.example.androidcompose.layout.RadioButtonSamplePreview
import com.example.androidcompose.ui.theme.AndroidComposeTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            AndroidComposeTheme {
                // A surface container using the 'background' color from the theme

                Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colors.background) {

                    RadioButtonSamplePreview()
//                    ColumnSamplePreview()
//                    SliderSamplePreview()
//                    ProgressIndicatorSamplePreview()
//                    TextFieldSamplePreview()
//                    SwitchSamplePreview()
//                    StateSamplePreview()
                //                    ButtonSamplePreview()
//                    IconSamplePreview()
                //                    ModifierSamplePreview()
                //                    Greeting("Android")
                }
            }
        }
    }
}

@Composable
fun Greeting(name: String) {
//    Text(text = "Hello $name!")
    val annotatedString = buildAnnotatedString {
        append("点击登录即代表您已知悉同意")

        pushStringAnnotation("protocol", "https://api.apachecn.org/kfc?tag=other")
        withStyle(style = SpanStyle (
            Color.Red,
            textDecoration = TextDecoration.Underline
        )) {
            append("《用户协议》")
        }
        pop()

        append("和")

        pushStringAnnotation("privacy", "我去，初音未来！")
        withStyle(style = SpanStyle (
            Color.Blue,
            textDecoration = TextDecoration.Underline
        )) {
            append("《隐私政策》")
        }
        pop()
    }

    ClickableText(text = annotatedString, onClick = {
        offset ->
        annotatedString.getStringAnnotations("protocol", start = offset, end = offset).firstOrNull()
            ?.let {
                annotation -> Log.d("========", "点击到了: ${annotation.item}")
            }
        annotatedString.getStringAnnotations("privacy", start = offset, end = offset).firstOrNull()
            ?.let {
                annotation -> Log.d("========", "点击到了: ${annotation.item}")
            }
//        Log.d("========", "点击到了: $it")
    })


//
//     ClickableText(text = buildAnnotatedString {
//            append("啦啦啦啦啦，")
//            withStyle(style = SpanStyle (
//                color = Color.Red,
//                textDecoration = TextDecoration.Underline
//            )) {
//                append("呜呜呜。")
//            }
//            append("寄了")
//        }, onClick = {
//            Log.d("=========", "你点击到 $it 了")
//        })
}

@Preview(showBackground = true, showSystemUi = true)
@Composable
fun DefaultPreview() {
    AndroidComposeTheme {
//        ModifierSamplePreview()
//        ButtonSamplePreview()
        Greeting("Android")
    }
}