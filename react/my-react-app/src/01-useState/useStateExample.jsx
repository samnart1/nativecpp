import { useState } from 'react'
import { data } from '../data'

const UseExample = () => {
  const [people, setPeople] = useState(data)

  const removePerson = (id) => {
    const newPeople = people.filter((person) => person.id !== id)
    setPeople(newPeople)
  }

  return (
    <div>
      {people.map((person) => {
        const { id, name } = person
        return (
          <div key={id}>
            <h2>{name}</h2>
            <button type="button" onClick={() => removePerson(id)}>
              Remove Person
            </button>
          </div>
        )
      })}
      <button
        type="button"
        onClick={() => setPeople([])}
        style={{ margin: '5rem' }}
      >
        Clear All
      </button>
    </div>
  )
}

export default UseExample
