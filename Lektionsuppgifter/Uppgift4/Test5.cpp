
















string filnamn;
  cout << "Ange filnamn: ";
  getline( cin, filnamn );
  
  // Öppna filen för läsning
  // (fin är en instans av ifstream)
  // skapa objektet fin

  ifstream fin( filnamn.c_str() ); 

  // Felkontroll

  if ( !fin ) 
    {
      cout << "Filen kunde inte öppnas"
           << endl;
      exit( EXIT_FAILURE );
    }

  // läs tecken för tecken

  char c;
  while ( fin.get(c) )
    {
      // och skriv varje tecken
      cout << c;
    }

  return 0;
}