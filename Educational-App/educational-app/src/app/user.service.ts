import { Injectable } from '@angular/core';
import { User } from './user';
import { PROFILES } from './mock-users';
import { Observable, of} from 'rxjs';

import { MessageService } from './message.service';
import { HttpClient, HttpHeaders } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})




export class UserService {
getUsers(): Observable<User[]> {
  const users = of(PROFILES);
  this.messageService.add('UserService: fetched users');
  return users;
}

getUser(id: number): Observable<User> {
  const user = PROFILES.find(u => u.id === id)!;
  this.messageService.add('UserService: fetched user id=${id}');
  return of(user);
}

  constructor(private messageService: MessageService) { }
}
