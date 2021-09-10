import { Injectable } from '@angular/core';
import {InMemoryDbService } from 'angular-in-memory-web-api';
import { User } from './user';

@Injectable({
  providedIn: 'root'
})
export class InMemoryDataService implements InMemoryDbService {
  createDb() {
    const users = [
      { id: 2, name: 'Bob' },
      { id: 3, name: 'PorkChop' },
      { id: 4, name: '3rd Person' },
      { id: 5, name: 'Aubrey'},
      { id: 6, name: 'Starfox'}
  ];
  return {users};
}



  constructor() { }
}
