package com.example.androidcompose.layout

import androidx.compose.animation.*
import androidx.compose.animation.core.Spring
import androidx.compose.animation.core.animateDpAsState
import androidx.compose.animation.core.spring
import androidx.compose.animation.core.tween
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.interaction.MutableInteractionSource
import androidx.compose.foundation.layout.*
import androidx.compose.material.Button
import androidx.compose.material.Icon
import androidx.compose.material.Text
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowForward
import androidx.compose.material.icons.filled.Favorite
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.androidcompose.R

@OptIn(ExperimentalAnimationApi::class)
@Composable
fun AnimationSample() {

    var visible by remember {
        mutableStateOf(false)
    }

    Column {
        Button(onClick = {
            visible = !visible
        }) {
            Text(text = "Toggle Visibility")
        }
        AnimatedVisibility(
            visible = visible,
            enter = slideInVertically { -40 } + expandIn(),
//            enter = scaleIn() + expandIn(),
            exit = fadeOut()
        ) {
            Image(
                painter = painterResource(id = R.drawable.nb),
                contentDescription = null
            )
        }
    }
}

@OptIn(ExperimentalAnimationApi::class)
@Composable
fun AnimationSample2() {
    var visible by remember {
        mutableStateOf(false)
    }
    Column {
        Button(onClick = {
            visible = !visible
        }) {
            Text(text = "点击！！！")

            AnimatedVisibility(
                visible = visible,
                enter = EnterTransition.None
            ) {
                Box(
                    modifier = Modifier
                        .size(300.dp)
                        .background(Color.Blue)

                ) {
                    Box(
                        modifier = Modifier
                            .animateEnterExit(
                                enter = slideInVertically(animationSpec = tween(1000)),
                                exit = slideOutVertically()
                            )
                            .size(150.dp)
                            .background(Color.Cyan)
                            .align(Alignment.Center)

                    )
                }
            }
        }
    }
}


@OptIn(ExperimentalAnimationApi::class)
@Composable
fun AnimationSample3() {

    var count by remember {
        mutableStateOf(0)
    }

    Row {
        Button(onClick = {
            count++
        }) {
            Text("Add")
        }
        Text("Count: $count")

        AnimatedContent(targetState = count) {
            targetCount -> Text("Count: $targetCount")
        }

    }
}

@OptIn(ExperimentalAnimationApi::class)
@Composable
fun AnimationSample4() {
    // 定义一个可变的state，初始值为0
    var count by remember {
        mutableStateOf(0)
    }

    // 创建一个水平布局
    Row {
        // 创建一个按钮，点击时count加1
        Button(onClick = {
            count++
        }) {
            Text("+")
        }
        // 创建一个按钮，点击时count减1
        Button(onClick = {
            count--
        }) {
            Text("-")
        }

        // 显示count的值
        Text("Count: $count")

        // 创建一个动画内容，根据count的值进行动画过渡
        AnimatedContent(
            targetState = count,
            transitionSpec = {
                // 如果目标状态大于初始状态，则向上滑动并淡入，向下滑动并淡出
                if (targetState > initialState) {
                    slideInVertically { fullHeight -> fullHeight } + fadeIn() with
                            slideOutVertically { fullHeight -> -fullHeight } + fadeOut()
                } else {
                    // 否则，向下滑动并淡入，向上滑动并淡出
                    slideInVertically { fullHeight -> -fullHeight } + fadeIn() with
                            slideOutVertically { fullHeight -> fullHeight } + fadeOut()
                }
            }
        ) {
                // 显示目标状态的值
                targetCount -> Text("Count: $targetCount")
        }

    }
}

@Composable
// 定义一个名为AnimationSample5的函数，用于展示动画效果
fun AnimationSample5() {
    // 使用remember函数创建一个可变的state，初始值为"Hello"
    var message by remember {
        mutableStateOf("Hello")
    }
    // 创建一个垂直方向的布局
    Column {
        // 创建一个按钮，点击时将message的值加上" World"
        Button(onClick = {
            message += " World"
        }) {
            // 在按钮上显示文本"Click me"
            Text("Click me")
        }
        // 在文本上显示message的值，并使用animateContentSize()函数实现动画效果
        Text(text = message, modifier = Modifier.animateContentSize())
    }
}

@Composable
fun AnimationSample6() {

    // 定义一个可变的State，初始值为40.dp
    var size by remember {
        mutableStateOf(40.dp)
    }

    // 使用animateDpAsState函数创建一个动画，目标值为size，动画规格为Spring.DampingRatioHighBouncy
    val sizeAnimation by animateDpAsState(
        targetValue = size,
        animationSpec = spring(Spring.DampingRatioHighBouncy)
    )

    // 创建一个Column，填充整个屏幕，垂直居中，水平居中
    Column (
        Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        // 创建一个Icon，图标为Favorites，颜色为红色
        Icon (
            imageVector = Icons.Default.Favorite,
            contentDescription = null,
            tint = Color.Red,

            // 设置Icon的大小为sizeAnimation，并添加点击事件，点击时size增加30.dp
            modifier = Modifier
                .size(sizeAnimation)
                .clickable(
                    interactionSource = MutableInteractionSource(),
                    indication = null
                ) {
                    size += 30.dp
                }
            )
    }
}


@Preview
@Composable
fun AnimationSamplePreview() {
    AnimationSample6()
}