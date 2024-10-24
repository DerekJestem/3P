package com.example.sprawdzian

import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.BorderStroke
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.border
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.text.BasicTextField
import androidx.compose.foundation.text.KeyboardActions
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Menu
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.sprawdzian.ui.theme.SprawdzianTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            SprawdzianTheme {
                Column (modifier = Modifier.fillMaxSize().background(Color.DarkGray), horizontalAlignment = Alignment.CenterHorizontally) {
                    title()

                    Text("Hello World! Welcome to 3bird Projects!", color = Color.White)
                    Text("Druga linia tekstu", color = Color.White)

                    HorizontalDivider(thickness = 2.dp)

                    boxes()

                    Spacer(modifier = Modifier.height(35.dp))
                    Text("Kamil Janik 3P",  modifier = Modifier.background(Color.White).padding(20.dp), fontFamily = FontFamily.Cursive, fontSize = 35.sp)

                    var textState by remember { mutableStateOf("") }

                    Spacer(modifier = Modifier.height(25.dp))
                    TextField(value = textState,
                        onValueChange = { newText -> textState = newText},
                        label = { Text("Wpisz tekst: ")})

                    image()
                    card()

                    button(textState)
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun title()
{
    val contextForToast = LocalContext.current.applicationContext
    Column() {
        TopAppBar(
            title = {Text("Nazwa aplikacji")},
            navigationIcon = {IconButton(onClick = {
                Toast.makeText(contextForToast, "Naciśnięto ikonę nawigacji.",
                    Toast.LENGTH_SHORT).show()
            }) {
                Icon(imageVector = Icons.Default.Menu,
                    contentDescription = "Menu")
            }
            },
            colors = TopAppBarDefaults.topAppBarColors(
                containerColor = Color.LightGray,
                titleContentColor = Color.Magenta)
        )
    }
}

@Composable
fun boxes()
{
    Row (modifier = Modifier
        .fillMaxWidth()
        .height(100.dp)
        .padding(horizontal = 24.dp, vertical = 8.dp)
        .background(Color.Gray),
        horizontalArrangement = Arrangement.SpaceAround,
        verticalAlignment = Alignment.CenterVertically){
        Box(modifier = Modifier.width(70.dp).height(70.dp),  contentAlignment = Alignment.Center) {
            Text("El 1")
        }
        Box(modifier = Modifier.width(70.dp).height(70.dp),  contentAlignment = Alignment.Center) {
            Text("El 2")
        }
        Box(modifier = Modifier.width(70.dp).height(70.dp).background(Color.Yellow),  contentAlignment = Alignment.Center) {
            Text("El 3")
        }
        Box(modifier = Modifier.width(70.dp).height(70.dp).background(Color.Yellow),  contentAlignment = Alignment.Center) {
            Text("El 4")
        }
    }
}

@Composable
fun image() {
    Spacer(modifier = Modifier.height(50.dp))
    Image(painter = painterResource(id = R.drawable.logo), contentDescription = "Android Image", modifier = Modifier.width(100.dp).height(100.dp))
}

@Composable
fun card()
{
    Spacer(modifier = Modifier.height(45.dp))
    Card (colors = CardDefaults.cardColors(
        containerColor = Color.Yellow,
    )) {
        Text("To jest karta.", modifier = Modifier.padding(top = 10.dp).padding(horizontal = 10.dp), fontWeight = FontWeight.Bold)
        Text("Zawiera elementy w kolumnie,",  modifier = Modifier.padding(horizontal = 10.dp, vertical = 0.dp))
        Text("czyli: element pod elementem",  modifier = Modifier.padding(bottom = 10.dp).padding(horizontal = 10.dp), color = Color.Gray)
    }
}

@Composable
fun button(text: String) {
    val context = LocalContext.current

    Spacer(modifier = Modifier.height(45.dp))
    Button(
        onClick = {
            Toast.makeText(context, "Przycisk klikniety, wiadomość: $text", Toast.LENGTH_SHORT).show()
        },
        colors = ButtonDefaults.buttonColors(Color(0xff006699)),
        border = BorderStroke(2.dp, Color.Gray)
    ) {
        Text(text = "Zatwierdź polecenie...", color = Color.Red, modifier =  Modifier.padding(10.dp))
    }
}
