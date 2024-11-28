package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.myapplication.ui.theme.MyApplicationTheme
import kotlin.concurrent.thread

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MyApplicationTheme {
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    WszystkieElementy()
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun WszystkieElementy() {
    var aktualnyStanProgresu by remember { mutableStateOf(0f) }
    var aktualnyStanProgresu2 by remember { mutableStateOf(0f) }
    var startLoading by remember { mutableStateOf(false) }
    var startLoading2 by remember { mutableStateOf(false) }

    Column(
        verticalArrangement = Arrangement.spacedBy(12.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = Modifier.fillMaxWidth()
    ) {
        CenterAlignedTopAppBar(
            title = {
                Column {
                    Text(
                        "Progress Bars",
                        fontSize = 26.sp,
                        fontWeight = FontWeight.Bold
                    )
                    Text(
                        "Autor: XYZ",
                        fontSize = 20.sp,
                        fontWeight = FontWeight.Bold
                    )
                }
            },
            colors = TopAppBarDefaults.centerAlignedTopAppBarColors(
                containerColor = Color.Green.copy(alpha = 0.3f)
            )
        )

        Spacer(modifier = Modifier.height(5.dp))
        Text("Statyczny liniowy:")
        LinearProgressIndicator()

        Spacer(modifier = Modifier.height(30.dp))
        Text("Statyczny kołowy:")
        CircularProgressIndicator()

        Spacer(modifier = Modifier.height(50.dp))
        Text("Dynamiczny liniowy:")
        Button(
            onClick = { startLoading = true },
            enabled = !startLoading
        ) {
            Text("Start loading")
        }
        if (startLoading) {
            LinearProgressIndicator(
                modifier = Modifier.fillMaxWidth(),
                color = Color.Green,
                progress = aktualnyStanProgresu
            )
            if (aktualnyStanProgresu < 1f) {
                LaunchedEffect(Unit) {
                    while (aktualnyStanProgresu < 1f) {
                        aktualnyStanProgresu += 0.01f
                        kotlinx.coroutines.delay(100)
                    }
                    startLoading = false
                    aktualnyStanProgresu = 0f
                }
            }
        }

        Spacer(modifier = Modifier.height(30.dp))
        Text("Dynamiczny kołowy:")
        Button(
            onClick = { startLoading2 = true },
            enabled = !startLoading2
        ) {
            Text("Start loading")
        }
        if (startLoading2) {
            CircularProgressIndicator(
                modifier = Modifier.size(120.dp),
                color = Color.Green,
                progress = aktualnyStanProgresu2
            )
            if (aktualnyStanProgresu2 < 1f) {
                LaunchedEffect(Unit) {
                    while (aktualnyStanProgresu2 < 1f) {
                        aktualnyStanProgresu2 += 0.01f
                        kotlinx.coroutines.delay(100)
                    }
                    startLoading2 = false
                    aktualnyStanProgresu2 = 0f
                }
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun Podglad() {
    MyApplicationTheme  {
        WszystkieElementy()
    }
}
